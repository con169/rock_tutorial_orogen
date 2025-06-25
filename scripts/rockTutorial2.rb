require 'vizkit'
require 'orocos'

## load and add the 3d plugin for the rock
Orocos.run 'rock_tutorial::RockTutorialControl' => 'rock_control' do
  rockControl = Orocos.name_service.get 'rock_control'
  rockControl.start

  ## Create a sample writer for a port ##
  sampleWriter = rockControl.motion_command.writer

  # get a sample that can be written to the port
  # If you know the sample type (here, base::MotionCommand2D),
  # an alternative syntax is
  #   sample = Types::Base::MotionCommand2D.new
  sample = sampleWriter.new_sample

  # create a widget that emulates a joystick
  joystickGui = Vizkit.default_loader.create_widget('VirtualJoystick')

  #show it
  joystickGui.show

  ## glue the widget to the task writer
  joystickGui.connect(SIGNAL('axisChanged(double,double)')) do |x, y|
    sample.translation = x
    sample.rotation = - y.abs() * Math::atan2(y, x.abs())
    sampleWriter.write(sample)
  end

  Vizkit.display rockControl.pose,
  :widget => Vizkit.default_loader.RigidBodyStateVisualization

  Vizkit.exec
end