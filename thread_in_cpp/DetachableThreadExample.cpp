# include <iostream>
# include <thread>
# include <chrono>


using namespace std;
std::thread::id MAIN_THREAD_ID;

/*
Calling detach() on a std::thread object leaves the thread to run in the back-ground, 
with no direct means of communicating with it.

if a thread becomes detached, it isn’t possible to obtain
a std::thread object that references it, so it can no longer be joined

Detached threads truly run in the background; ownership and control are passed over to the C++ Runtime Library
which ensures that the resources associated with the thread are correctly reclaimed when the thread exits
*/


/*
Detached threads are often called daemon threads after the UNIX concept of a dae-mon process 
that runs in the background without any explicit user interface

Such threads are typically long-running; they run for almost the entire lifetime of the appli-cation, 
performing a background task such as monitoring the filesystem, clearing unused entries out of object caches,
or optimizing data structures
*/
bool isEditing = false;
void open_document_and_display_gui(string const &filename)
{
    if (std::this_thread::get_id() == MAIN_THREAD_ID)
    {
        std::cout << "main thread\n";
    }
    else
    {
        std::cout << "not main thread\n";
        this_thread::sleep_for(chrono::seconds(2));
        cout << "Detached thread completed." << endl;

    }
    cout << "Openning filename: " << filename << " For Editing ...." << endl;
}

bool done_editing() {
    return isEditing;
}

enum command_type{
    open_new_document,
    close_document,
    append_document
};


struct UserCommand {
    command_type type;

    UserCommand () : type (open_new_document) {}
    
};

UserCommand getUserInput() {
    return UserCommand();
}

string get_filename_from_user() {
    return "sks_document.doc";
}

void process_user_input(UserCommand const& cmd) {
    cout << "User Input "<<cmd.type<<endl;
}

void edit_document(string const& filename)
{
    open_document_and_display_gui(filename);
    while(!done_editing())
    {
        isEditing = true;
        UserCommand cmd= getUserInput();
        if(cmd.type==open_new_document)
        {
            string const new_name=get_filename_from_user();
            thread t(edit_document,new_name);
            t.detach();
        }
        else
        {
            process_user_input(cmd);
        }
    }
}

int main () {
    MAIN_THREAD_ID = std::this_thread::get_id();

    edit_document("SKSNew.doc");

     cout << "Main thread continuing..." << endl;
    // Give some time for detached thread to complete
    this_thread::sleep_for(chrono::seconds(9));

    return 0;
}