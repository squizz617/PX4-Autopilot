#include <iostream>
#include <fstream>

#include "SampleSystem.hh"

//! [registerSampleSystem]
#include <gz/plugin/Register.hh>

// Include a line in your source file for each interface implemented.
GZ_ADD_PLUGIN(
    sample_system::SampleSystem,
    gz::sim::System,
    sample_system::SampleSystem::ISystemPostUpdate)
//! [registerSampleSystem]
//! [implementSampleSystem]
using namespace sample_system;

SampleSystem::SampleSystem()
{
  f.open("/tmp/plugin.log");
  f << "system plugin initializing\n";
}

SampleSystem::~SampleSystem()
{
  f.close();
}

void SampleSystem::PostUpdate(const gz::sim::UpdateInfo &_info,
    const gz::sim::EntityComponentManager &_ecm)
{
  // gzmsg << "SampleSystem::PostUpdate" << std::endl;
  f << "plugin PostUpdate\n";
}
//! [implementSampleSystem]
