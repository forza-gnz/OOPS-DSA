# CONFIGS
# =======
LAB_NO=6 # Lab Number
NUM_Qs=1 # Should be less than 10. Else the code needs modification.
ntests=10 # number of test cases
TIME_LMT=10 # time limit

# COLORS
# ======
NC='\033[0m'            # No Color
Bold='\033[1m'          # Bold
# Bold High Intensity
Red='\033[1;91m'        # Red
Green='\033[1;92m'      # Green
Yellow='\033[1;93m'     # Yellow
Cyan='\033[1;96m'       # Cyan

# Clean required folders and files and create fresh ones
rm -rf results
rm -rf actual_outputs
rm -rf total_marks_mk.txt

mkdir results
mkdir actual_outputs
for i in `seq 1 $NUM_Qs`
do
    mkdir actual_outputs/Q$i
    mkdir results/Q$i
    # Complete results will be contained in the file total.csv
    touch results/Q$i/total.csv
    echo "ROLLNUM,TOTAL" >> results/Q$i/total.csv
done

mkdir -p Programs

# Safety check
numoffiles=`ls Programs/ | wc -l`
if [ $numoffiles -eq 0 ]
then
    echo "Nothing to evaluate!"
    exit 1
fi

showFlag=0 # show marks result

#Compile and execute while creating needed directories
cd Programs
for dir in *
do
    # If directory name is wrong, skip and continue
    len=${#dir}
    echo
    echo "============="
    echo -e "${Cyan}$dir${NC}"
    echo "============="
    # Check if $dir matches pattern CS..B...-Lab.
    if [[ ! $dir =~ ^CS[0-9]{2}B[0-9]{3}-Lab${LAB_NO}$ ]]
    then
        echo -e "${Yellow}Skipping directory${NC} ${Bold}'$dir'${NC} because of ${Yellow}wrong name/directory/structure${NC}"
        echo -e "Valid directory name: ${Bold}CSXXBXXX-Lab${LAB_NO}${NC}"
        echo "********************************************************************************"
        continue
    fi
    
    let showFlag=1
    cd $dir
    rollNum=${dir%-Lab${LAB_NO}}

    for i in `seq 1 $NUM_Qs`
    do
        touch ../../results/Q$i/$rollNum.txt
        marks=0
        if [ $i -gt 1 ]
        then
            echo
        fi

        echo -e "${Bold}Q${i} Evaluation${NC}"
        echo "-------------"
        program="${dir}-Q${i}.cpp"
        # Main code file RollNum-LabX-QY.cpp does not exist
        if ! [ -f $program ]
        then
            echo "${dir}-Q${i} - Error: '${program}' not found. Main code file missing." >> ../../results/Q$i/$rollNum.txt
            echo "${rollNum},$marks" >> ../../results/Q$i/total.csv
            echo -e "${Bold}${dir}-Q${i}${NC} - ${Red}Error: '${program}' not found.${NC} Main code file missing."
            continue
        fi

        mkfl="Makefile"
        # Makefile does not exist
        if ! [ -f $mkfl ]
        then
            echo "${dir}-Q${i} - Error: '${mkfl}' not found." >> ../../results/Q$i/$rollNum.txt
            echo "${rollNum},$marks" >> ../../results/Q$i/total.csv
            echo -e "${Bold}${dir}-Q${i}${NC} - ${Red}Error: '${mkfl}' not found.${NC}"
            continue
        fi

        mkdir ../../actual_outputs/Q$i/$rollNum
        mkdir ../../actual_outputs/Q$i/$rollNum/sys_out ../../actual_outputs/Q$i/$rollNum/sys_err

        echo "Evaluating ${program}" >> ../../results/Q$i/$rollNum.txt
        echo -e "Evaluating ${Bold}$program${NC}" 
        if [ $program == "solution" ]
        then
            continue
        fi
            
        echo -e "Compiling ${Bold}$program${NC}"
        rm -rf ../../actual_outputs/Q$i/$rollNum/sys_out/*
        
        # make LXQY should generate executable
        # make "L${LAB_NO}Q${i}" # must use this when NUM_Qs > 1
        # make # can use this (without target name) for being flexible on target name in makefile
        # cpp file should compile
        target="L${LAB_NO}Q${i}"
        rm -rf *.o $target
        make ${target} 2> ../../actual_outputs/Q$i/$rollNum/sys_err/compile_err.txt
        if [ $? -ne 0 ]
        then
            rm -rf *.o
            echo "${dir}-Q${i} - Error: Makefile error / Compilation error" >> ../../results/Q$i/$rollNum.txt
            echo "${rollNum},$marks" >> ../../results/Q$i/total.csv
            echo "-------------"
            echo -e "${Bold}${dir}-Q${i}${NC} - ${Red}Error: Makefile error / Compilation error${NC}"
            echo -e "Error description available in ${Bold}'actual_outputs/Q${i}/${rollNum}/sys_err/compile_err.txt'${NC}"
            continue
        fi

        # executable generated should be named LxQY (same as target)
        if ! [ -f $target ]
        then
            rm -rf *.o
            echo "${dir}-Q${i} - Error: Executable generated is not named '$target'" >> ../../results/Q$i/$rollNum.txt
            echo "${rollNum},$marks" >> ../../results/Q$i/total.csv
            echo "-------------"
            echo -e "${Bold}${dir}-Q${i}${NC} - ${Red}Error: Executable generated is not named '$target'${NC}"
            continue
        fi

        echo -e "Executing generated-binary ${Bold}'$target'${NC} on $ntests test cases"
        for j in `seq 1 $ntests`
        do
            # ! CHECK: Input test case file name
            if [ $j -lt 10 ]
            then
                num=0$j
            else
                num=$j
            fi

            # pwd
            input=../../testcases/Q$i/input${num}.txt
            output=../../actual_outputs/Q$i/$rollNum/sys_out/output${num}.txt

            echo "testcase $j :"
            timeout $TIME_LMT "./${target}" $input $output || echo "Time limit exceeded"

            # Compare acutal and expected outputs using diff ignoring whitespaces
            # ! Use diff to compare files. 
            diff -wB ../../expected_outputs/Q$i/output${num}.txt ../../actual_outputs/Q$i/$rollNum/sys_out/output${num}.txt > ../../actual_outputs/Q$i/$rollNum/sys_err/diff_out${num}.txt
            if [ $? -eq 0 ]
            then
                echo "$testcase $j : PASS : 1" >> ../../results/Q$i/$rollNum.txt
                echo -e "${Green}PASS${NC}"
                # echo "$input : PASS : 1"
                let marks=marks+1
            else
                echo "testcase $j : FAIL : 0" >> ../../results/Q$i/$rollNum.txt
                echo -e "${Red}FAIL${NC}"
                # echo "$input : FAIL : 0"
            fi
        done

        rm -rf *.o $target
        echo "${dir}-Q${i} - #TCs passed for ${program}: ${marks}" >> ../../results/Q$i/$rollNum.txt
        echo "***" >> ../../results/Q$i/$rollNum.txt
        echo "${rollNum},$marks" >> ../../results/Q$i/total.csv
        echo "-------------"
        echo -e "${Bold}${dir}-Q${i}${NC} - ${Yellow}#TCs passed for ${program}: ${marks}${NC}"
    done

    echo "********************************************************************************"
    cd ../
done

cd ..
echo
echo -e "${Yellow}Evaluation completed!!!${NC}"
echo