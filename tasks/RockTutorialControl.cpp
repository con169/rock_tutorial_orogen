/* Generated from orogen/lib/orogen/templates/tasks/Task.cpp */

#include "RockTutorialControl.hpp"

using namespace rock_tutorial;

RockTutorialControl::RockTutorialControl(std::string const& name, TaskCore::TaskState initial_state)
    : RockTutorialControlBase(name, initial_state)
{
}

RockTutorialControl::~RockTutorialControl()
{
}



/// The following lines are template definitions for the various state machine
// hooks defined by Orocos::RTT. See RockTutorialControl.hpp for more detailed
// documentation about them.

bool RockTutorialControl::configureHook()
{
    if (! RockTutorialControlBase::configureHook())
        return false;
    return true;
}
bool RockTutorialControl::startHook()
{
    if (! RockTutorialControlBase::startHook())
        return false;
    return true;
}
void RockTutorialControl::updateHook()
{
    RockTutorialControlBase::updateHook();
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
