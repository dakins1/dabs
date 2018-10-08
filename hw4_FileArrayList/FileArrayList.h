//good lordy I am so fucked! AFJAIWEJFIA!!!!

template <typename T>
class FileArrayList {
	FileArrayList(const std::string &fname) { 
		f = fopen(fname.c_str(), "r+");
        if (f!=nullptr) {
            //something here about creating a new file???
        } else {
            f= fopen(fname.c_str(), "w+");
            //initialize empty array or something??? :(((
            
}
