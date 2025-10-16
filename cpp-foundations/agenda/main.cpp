#include <cstdlib>
#include "agenda.h"
#include <unordered_map>
#include <string>
#include <iostream>
#include <vector>



int main(){
     Agenda agenda;

    // Create contacts
    agenda.CreateContact("1", "Javier", "Garcia", "javier@mail.com", "123");
    agenda.CreateContact("2", "Alice", "Smith", "alice@mail.com", "456");

    // List contacts
    std::cout << "\nInitial contacts:\n";
    agenda.ListContacts();

    // Update a contact
    std::cout << "\nUpdating contact with ID '1':\n";
    agenda.UpdateContact("1", "Javier", "Garcia", "javier.garcia@newmail.com", "123-456-7890");
    
    // List contacts after update
    std::cout << "\nContacts after update:\n";
    agenda.ListContacts();

    // Delete a contact
    std::cout << "\nDeleting contact with ID '2':\n";
    agenda.DeleteContact("2");
    
    // List contacts after deletion
    std::cout << "\nContacts after deletion:\n";
    agenda.ListContacts();

    // Test error handling - try to update non-existent contact
    std::cout << "\nTesting error handling - updating non-existent contact:\n";
    try {
        agenda.UpdateContact("999", "Test", "User", "test@mail.com", "000");
    } catch (const std::runtime_error& e) {
        std::cout << "Error caught: " << e.what() << "\n";
    }

    // Test error handling - try to delete non-existent contact
    std::cout << "\nTesting error handling - deleting non-existent contact:\n";
    try {
        agenda.DeleteContact("999");
    } catch (const std::runtime_error& e) {
        std::cout << "Error caught: " << e.what() << "\n";
    }
}
