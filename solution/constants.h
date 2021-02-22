#pragma once

#include <vector>
#include <string>
#include "output/OutputData.h"
#include "input/InputData.h"

namespace constants {

    const std::vector<std::string> CSV_TABLE_NAMES = {
            "max_fly",
            "max_starts",
            "months",
            "params",
            "personal_levels",
            "quals",
            "qual_levels",
            "qualified",
            "required_personal",
            "rest_prior",
            "rest_req",
            "starts"
    };

    const std::vector<std::string> REST_CONSTANT_NAMES = {
            "REST_YEAR",
            "MIN_REST_SIZE",
            "MIN_REST_LAG",
            "TOTAL_RESTS",
            "PRIOR_RESTS",
            "NOPRIOR_RESTS",
            "REST_HIGH",
            "REST_LOW",
            "nMonths",
            "nQuals"
    };

    std::map<std::string, int> REST_CONSTANTS;

    const std::string CSV = ".csv";

    int MAX_PERSONAL_LEVEL = 0;
}