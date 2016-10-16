#include "stdafx.h"
#include "JenkinsRequestHelper.h"

JenkinsRequestHelper::JenkinsRequestHelper(std::string baseUrl, std::string port, std::string jobName) {
	url.append(baseUrl)
		.append(":")
		.append(port)
		.append("/job/")
		.append(jobName)
		.append("/lastBuild/api/json");

	std::cout << "url: " << url.c_str() << "\n";
}

pplx::task<BuildStatus> JenkinsRequestHelper::getCurrentStatus() {

	std::wstring widestr = std::wstring(url.begin(), url.end());
	uri uri(widestr.c_str());
	http_client client(uri);

	return client.request(methods::GET).then([](http_response response) -> 
		pplx::task<json::value> {
			if (response.status_code() == status_codes::OK){
				return response.extract_json();
			}

			// Handle error cases, for now return empty json value... 
			return pplx::task_from_result(json::value());
		})
		.then([](pplx::task<json::value> previousTask) {
			try {
				const json::value& json = previousTask.get();
				// Perform actions here to process the JSON value...
				BuildStatus status;	

				if (json.has_field(U("building"))) {
					status.isBuilding = json.at(U("building")).as_bool();
				}
				else {
					status.isBuilding = json.at(U("building")).as_bool();
				}

				if (json.has_field(U("result")) && !json.at(U("result")).is_null() ) {
					const utility::string_t result = json.at(U("result")).as_string();
					if (result == U("SUCCESS")) {
						status.result = BuildResult::success;
					}
					else if (result == U("UNSTABLE")) {
						status.result = BuildResult::unstable;
					}
					else if (result == U("FAILURE")) {
						status.result = BuildResult::failed;
					}
					else {
						status.result = BuildResult::unknown;
					}
				}
				else {
					status.result = BuildResult::unknown;
				}

				return status;
			}
			catch (const http_exception& e) {
				std::cout << e.what() << "\n";
			}
		});
}