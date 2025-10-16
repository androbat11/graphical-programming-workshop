#include "agenda.h"
#include <memory>
#include <vector>
#include <unordered_map>
#include <string>
#include <stdexcept>



Agenda::Agenda()
    : agenda_(std::make_unique<std::vector<std::unordered_map<std::string, std::string>>>()) {}


bool Agenda::ExistsById(const std::string& id) const {
    for (const auto& contact : *agenda_){
        auto it = contact.find("id");
        if (it != contact.end() && it->second == id){
            return true;
        }
    }

    return false;
}

void Agenda::CreateContact(const std::string& id, const std::string& name, const std::string& lastname,
			   const std::string& email, const std::string& phone) {
    
    if (ExistsById(id)){
        throw std::runtime_error("Contact with ID '" + id + "' already exists");
    }

	std::unordered_map<std::string, std::string> newContact = {
          {"id", id},
          {"name", name},
          {"lastname", lastname},
          {"email", email},
          {"phone", phone}
    };

	agenda_->push_back(std::move(newContact));
    std::cout << "Contact '" << name << " " << lastname << "' created successfully with ID: " << id << "\n";
}

void Agenda::ListContacts() const {
     if (agenda_->empty()) {
        std::cout << "No contacts in agenda.\n";
        return;
    }

    std::cout << "\n=== CONTACT LIST ===\n";
    std::cout << "Total contacts: " << agenda_->size() << "\n\n";
    
    int index = 1;
    for (const auto& contact : *agenda_) {
        std::cout << "[" << index << "] ";
        std::cout << "ID: " << contact.at("id") << " | ";
        std::cout << "Name: " << contact.at("name") << " " << contact.at("lastname") << " | ";
        std::cout << "Email: " << contact.at("email") << " | ";
        std::cout << "Phone: " << contact.at("phone") << "\n";
        ++index;
    }
    
}

void Agenda::UpdateContact(const std::string& id, const std::string& name, const std::string& lastname,
                          const std::string& email, const std::string& phone) {
    
    if (!ExistsById(id)) {
        throw std::runtime_error("Contact with ID '" + id + "' does not exist");
    }

    for (auto& contact : *agenda_) {
        if (contact.at("id") == id) {
            contact["name"] = name;
            contact["lastname"] = lastname;
            contact["email"] = email;
            contact["phone"] = phone;
            std::cout << "Contact with ID '" << id << "' updated successfully.\n";
            return;
        }
    }
}

void Agenda::DeleteContact(const std::string& id) {
    
    if (!ExistsById(id)) {
        throw std::runtime_error("Contact with ID '" + id + "' does not exist");
    }

    for (auto it = agenda_->begin(); it != agenda_->end(); ++it) {
        if (it->at("id") == id) {
            std::string name = it->at("name");
            std::string lastname = it->at("lastname");
            agenda_->erase(it);
            std::cout << "Contact '" << name << " " << lastname << "' with ID '" << id << "' deleted successfully.\n";
            return;
        }
    }
}
