#ifndef LEFTOVER_TRACKER_H_
#define LEFTOVER_TRACKER_H_

// Please fill in below.
// <Kalil Weaver>
// <CPSC 121L-20> (e.g. CPSC 121L-01)
// <04/17/2024>
// <KalilWeaver@csu.fullerton.edu>
// <KalilWeaver>
#include <map>
#include <vector>

#include "leftover_record.h"
#include "leftover_report.h"

class LeftoverTracker {
  // ======================= YOUR CODE HERE =======================
  // Write the LeftoverTracker class here. Refer to your class design for the
  // member variables, constructors, and member functions needed.
  //
  // Note: mark functions that do not modify the member variables
  // as const, by writing `const` after the parameter list.
  // Pass objects by const reference when appropriate.
  // Remember that std::string is an object!
  // ===============================================================

 public:
 
  // Member functions
  bool AddRecord(const LeftoverRecord& record);
  bool IsDuplicate(const LeftoverRecord& new_record) const;
  bool DeleteRecord(const LeftoverRecord &record);
  const std::vector<LeftoverRecord> &GetRecords() const;
  LeftoverReport GetLeftoverReport() const;




 private:
  std::vector<LeftoverRecord> leftover_records_;
};

#endif
