# nautonomous actuation selector {#nautonomous_actuation_selector}

This package is used to receive both autonomous (AutonomousOutput.cpp) and manual (ManualOutput.cpp) output, for propulsion, conveyor and lighting. Depending on priority (manual > autonomous) the OutputMultiplexer.cpp publishes those messages to 'multiplexed_propulsion', 'multiplexed_conveyor' and 'multiplexed_lighting'.

The packages [nautonomous_actuation_simulator](../../doxygen_nautonomous/html/nautonomous_actuation_simulator.html) and [nautonomous_actuation_synchronizer](../../doxygen_nautonomous/html/nautonomous_actuation_synchronizer.html) subscribe to those multiplexed messages. 

## Nodes
output_multiplexer

##Topics

###Subscribe
/autonomous_propulsion, /autonomous_conveyor, /autonomous_lighting <br /> /manual_propulsion, /manual_conveyor, /manual_lighting

###Publish
/multiplexed_propulsion, /multiplexed_conveyor, /multiplexed_lighting

## Files
[Include](dir_d60bf73a515735dff56209f4ec58ffdf.html)  |  [Src](dir_43c81b27ea54bdf7c3f062a318fb0ed9.html)


##Overview
![output_multiplexer.launch](../images/launch_output_multiplexer.png)
![legenda](../images/legenda.png)
