#pragma once
#include "stdafx.h"

//casablanca
#include <cpprest/http_client.h>
#include <cpprest/filestream.h>
#include <cpprest/json.h>                       // JSON library
#include <cpprest/uri.h>                        // URI library

using namespace utility;                    // Common utilities like string conversions
using namespace web;                        // Common features like URIs.
using namespace web::http;                  // Common HTTP functionality
using namespace web::http::client;          // HTTP client features
using namespace concurrency::streams;       // Asynchronous streams

enum BuildResult { success, unstable, failed, unknown };

struct BuildStatus {
	boolean isBuilding;
	BuildResult result;
	//DWORD buildStarted;
	//DWORD buildEnded;

	std::string toString() {
		std::string string;
		if (isBuilding) {
			string.append("building, ");
		}
		else {
			string.append("not building, ");
		}

		string.append(BuildStatus::toString(result));
		
		return string;
	}

	static std::string toString(BuildResult br) {
		std::string string;

		switch (br)
		{
		case success:
			string.append("successful");
			break;
		case unstable:
			string.append("unstable");
			break;
		case failed:
			string.append("failed");
			break;
		default:
			string.append("unknown");
		}

		return string;
	}
};

class JenkinsRequestHelper {
	
public:
	JenkinsRequestHelper(std::string baseUrl, std::string port, std::string jobName);
	pplx::task<BuildStatus> getCurrentStatus();
private:
	std::string url;
};