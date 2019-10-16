# no windowed mode
alias emacs='emacs -nw'
# git aliases
alias gs='git status'
alias gl='git log --max-count=6 --pretty=medium'
# gpvm commands
alias kfermi='kinit sbjones@FNAL.GOV'
alias kcern='kinit sejones@CERN.CH'
alias dune1='ssh -XY sbjones@dunegpvm01.fnal.gov'
alias dune2='ssh -XY sbjones@dunegpvm02.fnal.gov'
alias dune3='ssh -XY sbjones@dunegpvm03.fnal.gov'
alias dune4='ssh -XY sbjones@dunegpvm04.fnal.gov'
alias dune5='ssh -XY sbjones@dunegpvm05.fnal.gov'
alias dune6='ssh -XY sbjones@dunegpvm06.fnal.gov'
alias dune7='ssh -XY sbjones@dunegpvm07.fnal.gov'
alias dune8='ssh -XY sbjones@dunegpvm08.fnal.gov'
alias dune9='ssh -XY sbjones@dunegpvm09.fnal.gov'
alias dune10='ssh -XY sbjones@dunegpvm10.fnal.gov'
alias dune11='ssh -XY sbjones@dunegpvm11.fnal.gov'
alias dunebuild='ssh -XY sbjones@dunebuild01.fnal.gov'
# mount filesystem locally
alias dunemnt='sshfs sbjones@dunegpvm05.fnal.gov:/dune/app/users/sbjones ~/dune'
# mount data directory
alias dunedatamnt='sshfs sbjones@dunegpvm05.fnal.gov:/dune/data/users/sbjones ~/duneData'
# RHUL logins
alias rhul1='ssh -AXY sjones@linappserv1.pp.rhul.ac.uk'
alias rhul2='ssh -AXY sjones@linappserv2.pp.rhul.ac.uk'
alias rhul3='ssh -AXY sjones@linappserv3.pp.rhul.ac.uk'
alias rhulproxy='ssh -D 8080 -f -C -q -N sjones@linappserv2.pp.rhul.ac.uk'
# UCL login
alias plus1='ssh -AXY sjones@plus1.hep.ucl.ac.uk'
alias plus2='ssh -AXY sjones@plus2.hep.ucl.ac.uk'
# Log in to lxplus
alias lxplus='ssh -AXY sejones@lxplus.cern.ch'
# Aliases to turn bluetooth on and off via command line
alias bton='rfkill unblock bluetooth'
alias btoff='rfkill block bluetooth'
# Useful directories
alias cafana='cd ~/work/cafana/'
alias hptpc='cd ~/work/hptpc/'
alias meetings='cd ~/work/meetings/'
# Latex aliases to run the way I want
alias mylatex='pdflatex -synctex=1 -interaction=nonstopmode'

