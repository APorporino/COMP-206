
#Anthony Porporino (260863300)
#COMP206 Assignment 3
#My login script is .bash_profile since my shell is bash

echo "Welcome $USER to SOCS Bash!"
alias la='ls -la'
HISTSIZE=10
export PS1="$USER \w $"
who | grep 'fsimar\|twatso5'
#1 other thing of my liking: emojis and date plus time
echo 🚀 $(date)🤖
echo ""
echo ""

