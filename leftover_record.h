#ifndef LEFTOVER_RECORD_H_
#define LEFTOVER_RECORD_H_

// Please fill in below.
// <Kalil Weaver>
// <CPSC 121L-20> (e.g. CPSC 121L-01)
// <04/17/2024>
// <KalilWeaver@csu.fullerton.edu>
// <KalilWeaver>

#include <string>
#include <vector>

class LeftoverRecord {
  // ======================= YOUR CODE HERE =======================
  // Write the LeftoverRecord class here. Refer to your class design for the
  // member variables, constructors, and member functions needed.
  //
  // Note: mark functions that do not modify the member variables
  // as const, by writing `const` after the parameter list.
  // Pass objects by const reference when appropriate.
  // Remember that std::string is an object!
  // ===============================================================

 public:
  // default constructor
  LeftoverRecord();
  // Constructor
  /*
  LeftoverRecord(const std::string &date, const std::string &meal,
                 const std::string &food_name, double quantity,
                 const std::string &leftover_reason,
                 const std::string &disposal_mechanism, double cost);
*/
  
  // Accessors
  bool operator==(const LeftoverRecord& other) const;
  bool operator!=(const LeftoverRecord& other) const;

  std::string GetDate() const;
  std::string GetMeal() const;
  std::string GetFoodName() const;
  double GetQuantity() const;
  std::string GetLeftoverReason() const;
  std::string GetDisposalMechanism() const;
  double GetCost() const;

  // Mutators
  void SetDate(const std::string &date);
  void SetMeal(const std::string &meal);
  void SetFoodName(const std::string &food_name);
  void SetQuantity(double quantity);
  void SetLeftoverReason(const std::string &leftover_reason);
  void SetDisposalMechanism(const std::string &disposal_mechanism);
  void SetCost(double cost);




 private:
  // Member variables
  std::string date_;
  std::string meal_;
  std::string food_name_;
  double quantity_;
  std::string leftover_reason_;
  std::string disposal_mechanism_;
  double cost_;
};

#endif

