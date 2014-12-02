#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

string getCommandOption(const vector<string>&, const string&);
void setCommandOptions(vector<string>&, int, char**);
bool doesCmdOptionExist(const vector<string>& , const string&);

int main(int argc, char** argv)
{
    vector<string> args;
    setCommandOptions(args, argc, argv);

    string face_classifier_path = getCommandOption(args, "-face");
    if(!face_classifier_path.empty())
        cout << "The face classifier to use is: " << face_classifier_path << "\n";
    else
        cout << "Face classifier path not specified!\n";

    return 0;
}

string getCommandOption(const vector<string>& args, const string& opt) {
    string answer;
    vector<string>::const_iterator it = find(args.begin(), args.end(), opt);
    if(it != args.end() && (++it != args.end()))
        answer = *it;
    return answer;
}

void setCommandOptions(vector<string>& args, int argc, char** argv) {
    for(int i = 1; i < argc; ++i) {
        args.push_back(argv[i]);
    }
    return;
}

bool doesCmdOptionExist(const vector<string>& args, const string& opt) {
    vector<string>::const_iterator it = find(args.begin(), args.end(), opt);
    return (it != args.end());
}
