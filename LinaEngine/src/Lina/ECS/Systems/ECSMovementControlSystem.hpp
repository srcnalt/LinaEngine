/*
Author: Inan Evin
www.inanevin.com

Copyright 2018 Inan Evin

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, 
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions 
and limitations under the License.

Class: ECSMovementControlSystem
Timestamp: 4/9/2019 3:30:12 PM

*/

#pragma once

#ifndef ECSMovementControlSystem_HPP
#define ECSMovementControlSystem_HPP

#include "Lina/ECS/ECS.hpp"
#include "Lina/ECS/Components/ECSTransformComponent.hpp"
#include "Lina/ECS/Components/ECSMovementControlComponent.hpp"
namespace LinaEngine
{
	class ECSMovementControlSystem : public BaseECSSystem
	{

	public:

		ECSMovementControlSystem() : BaseECSSystem()
		{
			AddComponentType(ECSTransformComponent::ID);
			AddComponentType(ECSMovementControlComponent::ID);
		}

		virtual void UpdateComponents(float delta, BaseECSComponent** components);

	private:

	};
}


#endif