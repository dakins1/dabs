#include <csdio>

getNext(int node) {} //helper function

writeNext() //another helper function

int main() {
    FILE* f = fopen("testLists2.bin", "w+");
    //will need another constructor for when the file
    //does not already exist

    //step one is to write a sentinel
    fseek(f, sizeof(T), SEEK_SET);
    int prev=0; //value is whereever sentinel is. Could be 0, could be after 
                // a free list
    fwrite(&prev, sizeof(int), 1, f);
    int next=0;
    fwrite(&next, sizeof(int), 1, f); 
    //use fseek to go to a location

    //write freelist
    int freelist = 0//initially this is empty, use anything that is not a 
                    //natrual address
    fwirte(&freelist, sizeof(int), 1, f); //figure out what this func does
    //write sz
    //make sure you properly translate prev/next stuff
