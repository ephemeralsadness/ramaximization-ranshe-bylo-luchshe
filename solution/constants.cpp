#include "constants.h"

const std::vector<std::string> constants::CSV_TABLE_NAMES = {
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

const std::vector<std::string> constants::REST_CONSTANT_NAMES = {
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

std::map<std::string, int> constants::REST_CONSTANTS = {};

const std::string constants::CSV = ".csv";

int constants::MAX_PERSONAL_LEVEL = 0;