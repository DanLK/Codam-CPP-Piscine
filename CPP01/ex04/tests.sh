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
# test_replace "$simple_string" "files/remove.txt" "remove string" "cu" ''
test_replace "$simple_string" "files/simple.txt" "simple string" "cu" "CU"
test_replace "$simple_string" "files/contained.txt" "s1 contained in s2" "cu" "XcuX"


