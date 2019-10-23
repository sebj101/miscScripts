#!/bin/bash
# Sets up parameters to produce GENIE events in the DUNE LAr Near Detector
export GEOMETRY="/dune/app/users/sbjones/nd_sim/dunendggd/nd_hall_only_lar.gdml"  # or whatever (.root is okay too)
export TOPVOL="volWorld"                     # top volume in which to generate
export GPREFIX="larND"                       # file naming prefix

# GENIEXSECFILE is defined by UPS  setup genie_xsec ...

export GENLIST="Default"       # default generator list (no MEC) see below
                               # but might be "Default+CCMEC+NCMEC" or some such

export TUNE_FLAG="" 
# for GENIE v3 and beyond you  must also specify a tune
# if you setup a genie_xsec product you can use
#export TUNE_FLAG="--tune ${GENIE_XSEC_TUNE}" 

# quiet GENIE down ... by default it is _quite_ verbose
# this file should either be in a genie_xsec or genie_phyopt added path
# as part of $GXMLPATH cascade of locations
export MSGLVL=Messenger_production.xml
# or
# export MSGLVL=Messenger_laconic.xml
# or
#export MSGLVL=Messenger_whisper.xml
# Options for GSimpleNtpFlux
#export FLUXFILE=
#export DETLOC="NOTHINGSPECIAL"             # not relevant for gsimple flux files
                                           #   but needs to be non-blank
# Options for GDk2NuFlux
export FLUXFILE="/pnfs/dune/persistent/users/ljf26/fluxfiles/g4lbne/v3r5p4/QGSP_BERT/OptimizedEngineeredNov2017/neutrino/flux/dk2nu/g4lbne_v3r5p4_QGSP_BERT_OptimizedEngineeredNov2017_neutrino_00248.dk2nu.root"
export DETLOC="LBNE-NearDet_01"           # <param_set> name in first GNuMINtuple.xml file found

# Run specific parameters
export run=12345   # arbitrary run number
# one can either run for 
#   a fixed # of protons-on-target (for a sensible flux file)
#   a fixed # of generated events
# but not both 

# export EXPOSURE="-e 7.5e13"   # POT exposure
export EXPOSURE="-n 1000"     # number of events