#ifndef PROCESS_H
#define PROCESS_H

#include "storage_type.h"
#include <string>
#include "bin_loader.h"
#include <memory>
#include "loader.h"
#include "writer.h"
#include "vector.h"
#include "screen_writer.h"

using namespace std; 

class process {
    private:
        shared_ptr<loader> _loader;
        shared_ptr<storage_type> _storage;
        shared_ptr<writer> _writer;

    public:
        process(): _loader(make_shared<bin_loader>(bin_loader())), _storage(make_shared<vector>(vector())), _writer(make_shared<screen_writer>(screen_writer())) {};
        virtual ~process() {};
        virtual void execute();

    private: 
        virtual void choose_how_to_process();

};


#endif // PROCESS_H