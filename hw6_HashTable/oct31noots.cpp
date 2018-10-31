//decltype - declaring the type of something to be the type of some other thing
//tepname std::remove_reference.. table.begin() ..::type mainIter - depends on how the begin and end is implemented
//makes them the same type as table.begin()
//subIter is the same type as table[0].begin() cuz its a list
    //iterator or iterator reference?
    //if its not a reference to begin with, remove_reference does nothing
    //iter probs wont give you a reference, cuz we don't won't our changes to affect the actual
        //data stored

/* iterator constuctors */

//what happens if you pass two constructors
    //table.begin and table.end
    //begin gives you the first element of that container, but you don't know where that is
    //for if want it to be the first element of the first non-empty list
    //then subIter points to the first element of the non-empty list
    //firstElem == end() that means it's empty
//now what if you pass table.end() and table.end()
    //you want the end to not point/be anything
    //mainIter is set to end, subIter returns nothing
    //check whether mainIter is equal to end() iter, if so then you are at the end
    //subIter returns nothing because end() iterators don't point to elements

operator== 
    two cases:
        (1) want to see if both are equal to the end iterator / both equal to mainEnd()
        (2) if they are not equal to end, you check if the subIters are equal
        these are represented by || in operator==

operator* want to access the keyvalue pair stored at this location - dereference the subIter - easy

operator++ similar to first version of constructor -- seraches through the table to find the first non
    empty list -- if you are not the last element 
    while loop does this - keep going until you find a non-empty list
    if you find it, set subIter = mainIter->begin();
    --what happens if there is no next element? And what if you do ++?
        stopping condiditon for the while loop is (mainIter != mainEnd) 
    mainEnd is table.end() . . . ?
    so ++ on the last bucket will give you mainEnd
    main takeaway is how to use these -- find and insert
    return values for these are iterators -- idk what kind tho
    also erase uses iterators
        first version takes const_iterator - take ci and extract subIter or whatever and erase
            -extract the position? dereference the iterator to get the key then use the key?
                then call key's erase?
            - or vice-versa -- call one erase with the other by finding the key from the iterator
                or vice-versa
        - add friend class to const_iterator so you can attain its position data member
        second version takes a key 
        first way -- be careful with what kind of iterator you pass through
            maintain it is const or something
            erase itself is not a const function, but it's passed in a const_iterator
        make sure $g++ -v yeilds 4.9 or later
            if not, run $module load gcc -latest
            if you're extracting position from iter
    erase is taking the element and removing it from the container -- doesn't actually modify the
        value of the element - which is why const_iterator is passed through it
        but the reason to pass const_iterator over iterator is for user benefit
        - if you have an iterator, you can always conver it to a const_iterator
            iterator gives you read and write access
            but you can't go from const_iterator to iterator -- defeats purpose
            so for erase, you can pass an iterator and it'll automatically convert to const_iterator
            so its for this one-way compatability; gives the user more freedom since they can pass
                iterator or const_iterator in
                another reason is that mainIter is a const_iterator
const_cast 
^removes the const from a type or something 

outer iterator is an iterator of a vector
    random access iterator - has more features than regular iterator - can do pointer-like arithmetics
        more functions beyond ++ and -- 

