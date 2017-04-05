#include "memberlist.h"

MemberList::MemberList(): list(){}

MemberList::~MemberList()
{
    list.~LinkedList();
}

void MemberList::init_from_file(std::string filename)
{
    std::ifstream ifile;

    ifile.open(filename);

    if (ifile.is_open()){

        std::string temp, input_name;
        int input_id, input_type, input_month, input_day, input_year;

        while (getline(ifile, temp)){
            //member name
            input_name = temp;

            //member id
            getline(ifile,temp);
            input_id = std::stoi(temp);

            //membership type
            getline(ifile,temp);
            if (temp == "Basic"){
                input_type = 0;
            }
            else if (temp == "Preferred"){
                input_type = 1;
            }
            else{
                input_type = -1;
            }

            //member expiration date
            getline(ifile,temp,'/');
            input_month = std::stoi(temp);
            getline(ifile,temp,'/');
            input_day = std::stoi(temp);
            getline(ifile,temp,'\n');
            input_year = std::stoi(temp);

            list.push_back(Member(input_name, input_id, input_type, input_month, input_day, input_year));

        }
    }

    ifile.close();
}

Member MemberList::getMember(int n) const
{
    return list.get_nth(n);
}

int MemberList::length() const
{
    return list.length();
}
