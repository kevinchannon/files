cmake_minimum_required (VERSION 3.12)

include(FetchContent) # once in the project to include the module

FetchContent_Declare(wite
	URL https://github.com/kevinchannon/wite/releases/download/v1.0.0/wite.zip
	DOWNLOAD_EXTRACT_TIMESTAMP true
)

FetchContent_MakeAvailable(wite)