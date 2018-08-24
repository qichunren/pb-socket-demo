#include <stdio.h>
#include <string>

#include "addressbook.pb.h"

// This function fills in a Person message based on user input.
void PromptForAddress(tutorial::Person* person)
{
    int id = 100;
    person->set_id(id);
    char * name = "Qichunren";
    char * email = "whyruby@gmail.com";
    person->set_name(name);
    person->set_email(email);

    tutorial::Person::PhoneNumber* phone_number = person->add_phones();
    phone_number->set_number("07125554");
    phone_number->set_type(tutorial::Person::MOBILE);
}

int main(int argc, char * argv[])
{
    printf("Start tcp server.\n");

    GOOGLE_PROTOBUF_VERIFY_VERSION;
    tutorial::AddressBook address_book;
    // Add an address.
    PromptForAddress(address_book.add_people());

    int size = address_book.ByteSize();
    void *buffer = malloc(size);

    if(address_book.SerializeToArray(buffer, size))
    {
        printf("%s\n", (char *)buffer);
        printf("serialized ok, size %d\n", size);
    }


    return 0;
}
