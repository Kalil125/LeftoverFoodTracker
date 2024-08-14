// Please fill in below.
// <Kalil Weaver>
// <CPSC 121L-20> (e.g. CPSC 121L-01)
// <04/17/2024>
// <KalilWeaver@csu.fullerton.edu>
// <KalilWeaver>

#include "leftover_report.h"
#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
#include <unordered_map>


// ========================= YOUR CODE HERE =========================
// This implementation file is where you should implement
// the member functions declared in the header (leftover_report.h), only
// if you didn't implement them inline within leftover_report.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the LeftoverReport
// class.
// ===================================================================
LeftoverReport::LeftoverReport() = default;
LeftoverReport::LeftoverReport(
    const std::vector<LeftoverRecord>& leftover_records)
    : leftover_records_(leftover_records) {}

std::vector<std::string> LeftoverReport::MostCommonLeftover() const {
  // create a map
  std::map<std::string, int> leftover_counts;

  for (const LeftoverRecord& record : leftover_records_) {
    leftover_counts[record.GetFoodName()]++;
  }

  int max_count = 0;
  for (const auto& pair : leftover_counts) {
    if (pair.second > max_count) {
      max_count = pair.second;
    }
  }

  // the most common leftovers
  std::vector<std::string> most_common_leftovers;
  for (const auto& pair : leftover_counts) {
    if (pair.second == max_count) {
      most_common_leftovers.push_back(pair.first);
    }
  }

  return most_common_leftovers;
}

std::vector<std::string> LeftoverReport::MostCostlyLeftoverProducingMeals()
    const {
  // create a map
  std::map<std::string, int> leftover_meals;

  for (const LeftoverRecord& record : leftover_records_) {
    leftover_meals[record.GetMeal()]++;
  }

  int max_count = 0;
  for (const auto& pair : leftover_meals) {
    if (pair.second > max_count) {
      max_count = pair.second;
    }
  }

  //  the most common meals
  std::vector<std::string> most_common_meals;
  for (const auto& pair : leftover_meals) {
    if (pair.second == max_count) {
      most_common_meals.push_back(pair.first);
    }
  }

  return most_common_meals;
}
double LeftoverReport::TotalCostOfLeftover() const {
  double total_cost = 0.0;

  for (const LeftoverRecord& record : leftover_records_) {
    total_cost += record.GetCost();
  }

  return total_cost;
}

std::vector<std::string> LeftoverReport::MostCommonLeftoverReasons() const {
  std::map<std::string, int> leftover_reasons;

  for (const LeftoverRecord& record : leftover_records_) {
    leftover_reasons[record.GetLeftoverReason()]++;
  }

  int max_count = 0;
  for (const auto& pair : leftover_reasons) {
    if (pair.second > max_count) {
      max_count = pair.second;
    }
  }

  std::vector<std::string> most_common_leftover_reason_;
  for (const auto& pair : leftover_reasons) {
    if (pair.second == max_count) {
      std::string reason = pair.first;
      most_common_leftover_reason_.push_back(reason);
    }
  }

  return most_common_leftover_reason_;
}


std::vector<std::string> LeftoverReport::MostCommonDisposalMechanisms() const {
  std::map<std::string, int> disposal_mechanisms;

  for (const LeftoverRecord& record : leftover_records_) {
    disposal_mechanisms[record.GetDisposalMechanism()]++;
  }

  int max_count = 0;
  for (const auto& pair : disposal_mechanisms) {
    if (pair.second > max_count) {
      max_count = pair.second;
    }
  }

  // Correct the spelling of "Too much leftovers"
  std::vector<std::string> most_common_disposal_mechanisms;
  for (const auto& pair : disposal_mechanisms) {
    if (pair.second == max_count) {
      std::string mechanism = pair.first;
      most_common_disposal_mechanisms.push_back(mechanism);
    }
  }

  return most_common_disposal_mechanisms;
}


std::vector<std::string> LeftoverReport::SuggestLeftoverReductionStrategies() const {
  std::vector<std::string> suggested_strategies_to_reduce_leftover_;

    // Get the most common leftover reasons
    const std::vector<std::string>& most_common_reasons = MostCommonLeftoverReasons();

    if (most_common_reasons.empty()) {
        return suggested_strategies_to_reduce_leftover_;
    }

    // Define the suggested strategies based on the most common reasons
    if (std::find(most_common_reasons.begin(), most_common_reasons.end(), "Expired") != most_common_reasons.end()) {
        suggested_strategies_to_reduce_leftover_.push_back("Donate before expiration");
    }

    if (std::find(most_common_reasons.begin(), most_common_reasons.end(), "Too much left overs") != most_common_reasons.end()) {
        suggested_strategies_to_reduce_leftover_.push_back("Buy less food");
        suggested_strategies_to_reduce_leftover_.push_back("Cook small servings"); 
    }

    if (std::find(most_common_reasons.begin(), most_common_reasons.end(), "Tastes bad") != most_common_reasons.end()) {
        suggested_strategies_to_reduce_leftover_.push_back("Buy less food");
    }

    // Only suggest to recycle leftovers when not expired
    if (std::find(most_common_reasons.begin(), most_common_reasons.end(), "Expired") == most_common_reasons.end()) {
        suggested_strategies_to_reduce_leftover_.push_back("Recycle left overs");
    }

    // Ensure that the number of suggested strategies does not exceed 3
    if (suggested_strategies_to_reduce_leftover_.size() > 3) {
        suggested_strategies_to_reduce_leftover_.resize(3);
    }

    return suggested_strategies_to_reduce_leftover_;

}
  
    


      