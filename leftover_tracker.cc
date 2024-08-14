// Please fill in below.
// <Kalil Weaver>
// <CPSC 121L-20> (e.g. CPSC 121L-01)
// <04/17/2024>
// <KalilWeaver@csu.fullerton.edu>
// <KalilWeaver>

#include "leftover_tracker.h"
#include <algorithm>
#include <iostream>

// ========================= YOUR CODE HERE =========================
// This implementation file is where you should implement
// the member functions declared in the header (leftover_tracker.h), only
// if you didn't implement them inline within leftover_tracker.h.
//
// Remember to specify the name of the class with :: in this format:
//     <return type> MyClassName::MyFunction() {
//        ...
//     }
// to tell the compiler that each function belongs to the LeftoverTracker
// class.
// ===================================================================


bool LeftoverTracker::AddRecord(const LeftoverRecord &RecordToAdd) {
    // Iterate over existing records by reference to avoid unnecessary copies
    for (const LeftoverRecord& other : leftover_records_) {
        // Check if the current record is equal to the record being added
        if (other == RecordToAdd) {
            // If a duplicate is found, return false to indicate failure
            return false;
        }
    }
    // If no duplicate is found, add the record to the collection and return true
    leftover_records_.push_back(RecordToAdd);
    return true;
}

bool LeftoverTracker::DeleteRecord(const LeftoverRecord &record) {
 auto it = std::find(leftover_records_.begin(), leftover_records_.end(), record);

    // Check if the record was found
    if (it != leftover_records_.end()) {
        // Remove the record from the vector
        leftover_records_.erase(it);
        return true; // Record deleted successfully
    } else {
        return false; // Record not found, delete operation failed
    }
}

  

const std::vector<LeftoverRecord>& LeftoverTracker::GetRecords() const {
  return leftover_records_;
}
LeftoverReport LeftoverTracker::GetLeftoverReport() const {
  return LeftoverReport(leftover_records_);
}