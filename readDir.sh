#!/bin/bash
# Suhithareddy Kantareddy
# CSE 222
# Assignment: Reading Directories 

#getContents() function, which takes in file type/extension
getContents() {
    types=$1
    #if no type is provided it prints an error
    if [ -z "$types" ]; then
        echo "Please specify your type"
        return 1;
    fi
    data=($(ls *.$types))
}

#function to displat the contents of the array
display(){
    echo ${data[*]}
    for item in "${data[@]}"; do 
        echo "$item"
    done
}

#function to write the contents of the array to a file
write(){
    name=$1
    if [ -z "$name" ]; then
        echo "No filename specified"
        return 1
    fi 
    printf "%s\n" "${data[@]}" > "$name"
    echo "Data written to $name"
}

#the main interface of the script which prints out a menu of options for the user to choose from.

while true; do
    echo "Choose an Option:"
    echo "1. Get Contents"
    echo "2. Display"
    echo "3. Write"
    echo "4. Exit"
    read option

    case $option in
        1)
            #takes user input to type what file they'd search for
            echo "Enter the type of file you want to get (eg. txt, pdf):"
            read types
            unset data
            declare -a data
            getContents "$types"
            ;;
        2) 
            #displays all contents of array
            display 
            ;;
        3)
            #takes user input to which file to write to.
            echo "Enter the filename to Write:"
            read name
            write "$name"
            ;;
        4)
            echo "exiting"
            exit 0
            ;;
        *)
            echo "Invalid option. Choose again"
            ;;
    esac
done