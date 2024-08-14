#ifndef LEFTOVER_REPORT_H_
#define LEFTOVER_REPORT_H_
#include <string>
#include <vector>

#include "leftover_record.h"
// Please fill in below.
// <Kalil Weaver>
// <CPSC 121L-20> (e.g. CPSC 121L-01)
// <04/17/2024>
// <KalilWeaver@csu.fullerton.edu>
// <KalilWeaver>

class LeftoverReport {
  // ======================= YOUR CODE HERE =======================
  // Write the LeftoverReport class here. Refer to your class design for the
  // member variables, constructors, and member functions needed.
  //
  // Note: mark functions that do not modify the member variables
  // as const, by writing `const` after the parameter list.
  // Pass objects by const reference when appropriate.
  // Remember that std::string is an object!
  // ===============================================================

 public:
  LeftoverReport();
  LeftoverReport(const std::vector<LeftoverRecord> &leftover_records);

  std::vector<std::string> MostCommonLeftover() const;
  std::vector<std::string> MostCostlyLeftoverProducingMeals() const;
  double TotalCostOfLeftover() const;
  std::vector<std::string> MostCommonLeftoverReasons() const;
  std::vector<std::string> MostCommonDisposalMechanisms() const;
  std::vector<std::string> SuggestLeftoverReductionStrategies() const;

 private:
  std::vector<LeftoverRecord> leftover_records_;
};

#endif
