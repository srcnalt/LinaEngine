/*
Author: Inan Evin
www.inanevin.com

Copyright 2018 Inan Evin

Licensed under the Apache License, Version 2.0 (the "License"); you may not use this file except in compliance with the License. You may obtain a copy of the License at

http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing, software distributed under the License is distributed on an "AS IS" BASIS, 
WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. See the License for the specific language governing permissions 
and limitations under the License.

Class: Vertex
Timestamp: 1/7/2019 2:10:38 PM

*/

#pragma once

#ifndef Vertex_HPP
#define Vertex_HPP

#include "Utility/Math/Vector.hpp"

namespace LinaEngine
{
	class Vertex
	{
	public:

	
		Vertex(Vector3F position = Vector3F::ZERO(), Vector2F textureCoord = Vector2F::ZERO(), Vector3F n = Vector3F::ZERO()) : m_Position(position), m_TextureCoordinates(textureCoord) /*,m_Normal(n)*/ {};
		
		/* Setters and getters for position, normal and texture coordinates. */
		inline void SetPosition(const Vector3F& v) { m_Position = v; }
		//inline void SetNormal(const Vector3F& v) { m_Normal = v; }
		inline void SetTextureCoordinates(Vector2F v) { m_TextureCoordinates = v; }
		inline Vector3F GetPosition() { return m_Position; }
		//inline Vector3F GetNormal() { return m_Normal; }
		inline Vector2F GetTextureCoordinates() { return m_TextureCoordinates; }

		//static void CalcNormals(const unsigned int* pIndices, unsigned int IndexCount, Vertex* pVertices, unsigned int VertexCount);
	private:

		Vector3F m_Position;	// ORDER IMPORTANT
		Vector2F m_TextureCoordinates;	// ORDER IMPORTANT
		//Vector3F m_Normal;	// ORDER IMPORTANT
	};
}


#endif