/*
Author: Inan Evin
www.inanevin.com

MIT License

Lina Engine, Copyright (c) 2018 Inan Evin

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"),
to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense,
and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY,
WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.

4.0.30319.42000
10/18/2018 9:59:35 PM

*/

#pragma once

#ifndef Lina_PointLight_H
#define Lina_PointLight_H

#include "Lina_BaseLight.h"
#include "Lina_Attenuation.h"

class Lina_PointLight
{

public:

	Lina_PointLight() {};
	Lina_PointLight(Vector3 pos) : position(pos) {};
	Lina_PointLight(Vector3 color, float intensity) : base(Lina_BaseLight(color, intensity)) {};
	Lina_PointLight(Vector3 color, float intensity, Vector3 pos) : base(Lina_BaseLight(color, intensity)), position(pos) {};
	Lina_PointLight(Vector3 color, float intensity, Vector3 pos, float constant, float linear, float at) : base(Lina_BaseLight(color, intensity)), position(pos), attenuation(Lina_Attenuation(constant, linear, at)) {};
	Lina_PointLight(Lina_BaseLight b, Lina_Attenuation at) : base(b), attenuation(at) {};

	Vector3 position;
	Lina_BaseLight base;
	Lina_Attenuation attenuation;
};


#endif