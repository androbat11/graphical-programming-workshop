#pragma once

#include <memory>
#include <string>
#include <unordered_map>
#include <vector>
#include <iostream>

class Agenda {
 public:
    Agenda();

    void CreateContact(const std::string& id, const std::string& name,
                       const std::string& lastname, const std::string& email,
                       const std::string& phone);

    void ListContacts() const;
    
    void UpdateContact(const std::string& id, const std::string& name,
                       const std::string& lastname, const std::string& email,
                       const std::string& phone);
    
    void DeleteContact(const std::string& id);

 private:
    bool ExistsById(const std::string& id) const;

    std::unique_ptr<std::vector<std::unordered_map<std::string, std::string>>> agenda_;
};


// *********** THINKING PROCESS *********** //
//
// In order to create the agenda we need 3 operations:
// 1. Create contact. Data => name, lastname, email and phone
// 2. Modify contact
// 3. Delete contact
// 4. List contacts
