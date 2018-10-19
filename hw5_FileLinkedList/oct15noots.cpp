#include <cstdio>

typedef char T;

int ReadPrev(int node, FILE* file) {
    fseek(file,node+sizeof(T) , SEEK_SET);
        //moving to a small location 
        //inside the node
    int temp;
    fread(&temp, sizeof(int), 1, file );
        //this reads an address
    return temp;
}

int WritePrev(int node, int value, FILE* file) {
    //essentially do the same thing as in ReadPrev,
    //but use fwrite
}

int ReadNext(int node, FILE* file) {
    fseek(file, node+sizeof(T)+sizeof(int), SEEK_SET);
    int temp;
    fread(&temp, sizeof(int), 1, file );
        //this reads an address
    return temp;

}

int ReadData(int node, FILE* file) {
    fseek(file, node, SEEK_SET);
    T temp;
    fread(&temp, sizeof(T), 1, file);
    return temp;
}

    //make sure you're always reading from the write type,
    //the compile will not tell you if you're wrong

//node allocation and deallocation helper funcs

AllocateNode(FILE* file) { 
    int freeList 
    fseek(file, sizeof(Node) /*requires struct node*/, SEEK_SET);
        //or do sizeof(int) + sizeof(int) + sizeof(T)
    fread(&freeList, sizeof(int), 1, f);
    int temp;
    if (freeList!=-1) /*-1 meaning empty*/ {
        temp = freeList; 
        freeList = ReadNext(freeList, file);
        fseek(file, sizeof(Node) /*requires struct node*/, SEEK_SET);
        //or do sizeof(int) + sizeof(int) + sizeof(T)
        fread(&freeList, sizeof(int), 1, f);
    } else { //if free list is empty
        temp = sizeof(Node) + 2*sizeof(int) + sz*sizeof(Node); 
    }

    return temp;
}



int main() {
    FILE *f = fopen("testList2018.bin", "w+");

    //start with sentinel at 0
    //  //writing prev of sentinel
    fseek (f, sizeof(char), SEEK_SET);
    int prev = 0;
    fwrite(&prev, sizeof(int), 1, f);
    int next = 0;
    fwrite(&next, sizeof(int), 1, f);

    //freeList
    int freeList = -1;
    fwrite(&freeList, sizeof(int), 1, f);

    //sz
    int sz = 0;
    fwrite(&sz, sizeof(int), 1, f);
}

/*
Look at example code online
freeList is only created when erase is called for the first time
Freelist is its own linked list deal
stuff points to addresses
guuuuhhh fuck this dude
*/
