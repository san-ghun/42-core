# shells are an orchestration environment
# the language they provide is intended to orchestrate processes
# on the operating system
# if programs are functions, then all of the below are variants of function application

# anonymous pipe
echo "string" | cat

# herestring
cat <<< "string"

# herestring with command substitution
cat <<< $(echo "string")

# redirect stdin from process substitution
cat < <(echo "string")

# heredoc
cat << EOF
string
EOF

# heredoc ignoring leading tabs on each line
cat <<- EOF
	string
EOF

# heredoc literal - ignores interpolation and evaluation
cat << 'EOF'
$string
EOF


# piping
# ./pipex infile "grep a1" "wc -w" outfile 
# ./pipex infile "ls -l" "grep po" "wc -l" outfile  
< infile grep a1 | wc -w > outfile  

# heredoc piping
# ./pipex here_doc "a2" "grep a1" "wc -w" bfile
grep a1 << a2 | wc -w >> bfile
