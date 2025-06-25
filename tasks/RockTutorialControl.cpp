/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "RockTutorialControl.hpp"
#include <base/Time.hpp>

using namespace rock_tutorial;

RockTutorialControl::RockTutorialControl(std::string const &name, TaskCore::TaskState initial_state)
    : RockTutorialControlBase(name, initial_state), control(nullptr), taskPeriod(0)
{
}

RockTutorialControl::~RockTutorialControl()
{
    delete control;
}

/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See RockTutorialControl.hpp for more detailed
// documentation about them.

bool RockTutorialControl::configureHook()
{
    if (!RockTutorialControl::configureHook())
        return false;
    return true;
}
bool RockTutorialControl::startHook()
{
    // delete last instance in case we got restarted
    if (control)
        delete control;

    // create instance of the controller
    control = new RockControl();

    // figure out the period in which the update hook get's called
    taskPeriod = TaskContext::getPeriod();

    return RockTutorialControlBase::startHook();
}
void RockTutorialControl::updateHook()
{
    RockTutorialControlBase::updateHook();
    // read new motion command if available
    base::commands::Motion2D motionCommand;
    _motion_command.readNewest(motionCommand);

    // compute new position based on the input command
    base::samples::RigidBodyState rbs =
        control->computeNextPose(taskPeriod, motionCommand);

    // set time stamp
    rbs.time = base::Time::now();

    // write pose on output port
    if (_pose.connected())
        _pose.write(rbs);
}
void RockTutorialControl::errorHook()
{
    RockTutorialControlBase::errorHook();
}
void RockTutorialControl::stopHook()
{
    RockTutorialControlBase::stopHook();
}
void RockTutorialControl::cleanupHook()
{
    RockTutorialControlBase::cleanupHook();
}
