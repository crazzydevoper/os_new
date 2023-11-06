#!/bin/bash

clear
choice=1
while [ "$choice" -lt 8 ]
do
    echo -e "1. Create Address Book\n2. View Records\n3 .Insert new Record\n4. Delete a Record\n5. Modify a Record\n6. Search a record\n7. Exit\n\n"
    read choice

case $choice in
1)

    echo "Enter the filename: "
    read fileName
 
    if [ -e $fileName ]; then 
        rm $fileName 
    fi

    cont=1
    echo -e "ID \t\t Name \t\t\t Email \t\t Phone Number\n=========================================================\n" | cat >> $fileName
    echo "File created successfully"

    while [ "$cont" -gt 0 ]
		do
            echo -e "\nEnter ID : "
		read id
		echo -e "\nEnter Name : "
		read name
            patn="^[A-Za-z]"
            while [[ ! "$name" =~ $patn ]]   
            do
                echo "enter valid Name:"
                read name
            done

            echo -e "\nEnter email : "
		read email

            patem="^[a-z0-9._%-+]+@[a-z]+\.[a-z]{2,4}$"
            while [[ ! "$email" =~ $patem ]]
            do
                    echo "please enter valid email address"
                    read email
            done

			echo -e "Enter Phone Number of  $name"
			read ph_no

            pat_num="^[0-9]{10}$"
            while [[ ! $ph_no =~ $pat_num ]]
            do
                    echo "please enter valid phone number"
                    read ph_no
            done
        echo -e " $id \t\t $name \t\t $email \t\t $ph_no" | cat >> $fileName
        echo -e "Enter 0 to Stop, 1 to Enter next :"
        read cont
	done
;;

2)
    cat $fileName
;;

3)
    echo -e "\nEnter ID : "
    read id
    echo -e "\nEnter Name : "
    read name
    patn="^[A-Za-z]"
    while [[ ! "$name" =~ $patn ]]   
    do
            echo "enter valid Name:"
            read name
    done

    echo -e "\nEnter email : "
    read email

    patem="^[a-z0-9._%-+]+@[a-z]+\.[a-z]{2,4}$"
    while [[ ! $email =~ $patem ]]
    do
            echo "please enter valid email address"
            read email
    done


    echo -e "Enter Phone Number of  $name"
    read ph_no

    pat_num="^[0-9]{10}$"
    while [[ ! $ph_no =~ $pat_num ]]
    do
            echo "please enter valid phone number"
            read ph_no
    done
    echo -e " $id \t\t $name \t\t $email \t\t $ph_no" | cat >> $fileName

;;

4)
        echo -e "Enter the ID of the record you want to delete"
        read id
        sed -i "/$id/d" $fileName
;;

5)

    echo -e "Modify record\nEnter ID of record whose details you want to modify"
    read pattern 
    temp="temp"  
    grep -v $pattern $fileName | cat >> $temp    #IT is used to filter out lines in a file that do not contain the value stored in pattern   -v is used to select line that do not match 
    rm $fileName
    cat $temp | cat >> $fileName
    rm $temp
    echo -e "\nEnter ID : "
    read id
    echo -e "\nEnter Name : "
    read name
    patn="^[A-Za-z]"
    while [[ ! "$name" =~ $patn ]]   
    do
            echo "enter valid Name:"
            read name
    done

    echo -e "\nEnter email : "
    read email

    patem="^[a-z0-9._%-+]+@[a-z]+\.[a-z]{2,4}$"
    while [[ ! $email =~ $patem ]]
    do
            echo "please enter valid email address"
            read email
    done


    echo -e "Enter Phone Number of  $name"
    read ph_no

    pat_num="^[0-9]{10}$"
    while [[ ! $ph_no =~ $pat_num ]]
    do
            echo "please enter valid phone number"
            read ph_no
    done



    echo -e " $id \t\t $name \t\t $email \t\t $ph_no" | cat >> $fileName
;;


6)

echo "Enter the ID of the record you want to search"
read id


if grep -i "$id" $fileName ;
then
	echo "Record Found"
else 
	echo "Record Not Found";
fi
;;


7)
echo "Exit"
exit
;;

esac
done
exit