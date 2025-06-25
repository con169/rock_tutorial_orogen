require 'orocos'
require 'readline'
include Orocos

## Initialize orocos ##
Orocos.initialize

## load and add the 3d plugin for the rock
Orocos.run 'rock_tutorial::RockTutorialControl' => 'rock_tutorial_control' do


  rockControl = Orocos.name_service.get 'rock_tutorial_control'    

  ## Create a sample writer for a port ##
  sampleWriter = rockControl.motion_command.writer
  
  ## Start the tasks ##
  rockControl.start
  
  ## Write motion command sample ##
  sample = sampleWriter.new_sample
  sample.translation = 1
  sample.rotation = 0.5
  sampleWriter.write(sample)

  Readline::readline("Press Enter to exit\n") do
  end
end