# !bin/bash

RED='\033[0;31m'
NC='\033[0m'
GREEN='\033[032m'

mkdir files
simple_string='Hellocu Icu amcu acu cutext file\n
Exacumple\n
More linescu cu cu to read\n
\n
Aftercu an empty line I still read\n
\n
'

test_replace(){
  string=$1
  filename=$2
  testname=$3
  s1=$4
  s2=$5
  replacefile=$filename.replace
  sedfile=$filename.sed

  echo ""
  echo $string > $filename
  echo "Testing  $testname ... $filename... "

  ./string_replace $filename $s1 $s2
  sed "s/$s1/$s2/g" $filename >> $sedfile
  if test -e $replacefile
  then
    if diff $replacefile $sedfile
    then
      echo "${GREEN}[$testname]${NC} $replacefile created;output matches"
    else
      echo "${RED}[$testname]${NC} $replacefile created; output doesn't match"
    fi
  else
    echo "${RED}[$testname]${NC} $replacefile does not exist"
  fi
}

test_replace "$simple_string" "files/nostring.txt" "non-existing string" "xxxxxxx" "hello"


test_replace "$simple_string" "files/remove.txt" "remove string" "cu" "co"

# echo "Testing empty file..."
# filename="files/empty.txt"
# echo -n "" > $filename
# ./string_replace $filename x w
# if test -e $filename.replace
# then
#   if test -s $filename.replace
#   then
#     echo "${RED}[empty file]${NC} $filename.replace is not empty"
#   else 
#     echo "${GREEN}[empty file]${NC} $filename.replace created and empty."
#   fi
# else
#   echo "${RED}[empty file]${NC} $filename.replace does not exist."
# fi

# echo ""
# filename=files/nostring.txt
# echo $simple_string > $filename
# echo "Testing simple file, non-existent string... nostring.txt..."
# replacefile=$filename.replace
# sedfile=$filename.sed
# ./string_replace $filename "xxxxxxxxxxxxxx" hello
# sed 's/xxxxxxxxxxxxxx/hello/g' $filename >> $sedfile
# if test -e $replacefile
# then
#   if diff $replacefile $sedfile
#   then
#     echo "${GREEN}[simple file/non-existent string]${NC} $replacefile created;output matches"
#   else
#     echo "${RED}[simple file/non-existent string]${NC} $replacefile created; output doesn't match"
#   fi
# else
#   echo "${RED}[simple file/non-existent string]${NC} $replacefile does not exist"
# fi


# echo ""
# echo "Testing simple file, removing a string... remove.txt..."
# filename=files/remove.txt
# echo $simple_string > $filename
# replacefile=$filename.replace
# sedfile=$filename.sed
# ./string_replace $filename cu ""
# sed 's/cu//g' $filename >> $sedfile
# if test -e $replacefile
# then
#   if diff $replacefile $sedfile
#   then
#     echo "${GREEN}[simple file/remove string]${NC} $replacefile created;output matches"
#   else
#     echo "${RED}[simple file/remove string]${NC} $replacefile created; output doesn't match"
#   fi
# else
#   echo "${RED}[simple file/remove string]${NC} $replacefile does not exist"
# fi
