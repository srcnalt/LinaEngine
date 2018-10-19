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
10/16/2018 6:12:10 PM

*/

#include "pch.h"
#include "Scene/Lina_Scene.h"  
#include "Utility/Lina_ResourceLoader.h"
#include "Utility/Lina_Time.h"
#include "Utility/Lina_Globals.h"
#include "Scene/Lina_Camera.h"

Lina_Scene::Lina_Scene()
{

}

Lina_Camera Lina_Scene::GetCamera() { return sceneCamera; }

void Lina_Scene::Wake()
{

	// Plane 
	std::vector<Vertex> vertices;

	float depth = 10.0f;
	float width = 10.0f;
	vertices.push_back(Vertex(Vector3(-width, 0.0, -depth), Vector2(0.0, 0.0)));
	vertices.push_back(Vertex(Vector3(-width, 0.0, depth *3), Vector2(0.0, 1.0)));
	vertices.push_back(Vertex(Vector3(width *3, 0.0f, -depth), Vector2(1.0, 0.0)));
	vertices.push_back(Vertex(Vector3(width * 3, 0.0f, depth * 3), Vector2(1.0, 1.0f)));

	for (int i = 0; i < vertices.size(); i++)
	{
		std::cout << Vector3::VToString(vertices[i].GetPosition()) << std::endl;
	}
	std::vector<unsigned int> indices =
	{				0,1,2,2,1,3
	};



	material.color = (Vector3(1, 1, 1));
	material.texture = (Lina_ResourceLoader::LoadTexture("grid.png"));
	material.specularIntensity = 2;
	material.specularExponent = 8;

	transform.SetCamera(sceneCamera);
	transform.SetProjection(FIELD_OF_VIEW, WINDOW_WIDTH, WINDOW_HEIGHT, CLIPPING_PLANE_NEAR, CLIPPING_PLANE_FAR);

	s.SetAmbientLight(Vector3(0.1f, 0.1f, 0.1f));
//	s.SetDirectionalLight(Lina_DirectionalLight(Lina_BaseLight(Vector3(1,1,1) * 0.5f, 0.1f), Vector3(1,1,1)));
	p1 = Lina_PointLight(Vector3(1, 0, 0), 5.0f, Vector3(12.5, 0.5, 0), 0, 0, 1);
	p2 = Lina_PointLight(Vector3(0, 0, 1), 5.0f, Vector3(0, 0.5, 0), 0,0,2);

	pLights.push_back(p1);
	pLights.push_back(p2);
	s.SetPointLights(pLights);

	s.Init();

	m.InitMesh();
	//Lina_ResourceLoader::LoadMesh("sphere.obj");
	m.AddVertices(vertices, indices, true);
}


void Lina_Scene::Start()
{

}


void Lina_Scene::ProcessInput()
{


}

float temp = 0.0f;

void Lina_Scene::Update()
{
	temp += Lina_Time::GetDelta() ;
	transform.SetPosition(0, -1, 0);
//	transform.SetRotation(0, sin(temp) * 180, 0);
	sceneCamera.TempInput();

	//s.SetPointLights(pLights);

}

void Lina_Scene::Render()
{
	s.Bind();
	m.Draw();
	s.UpdateUniforms(transform.GetTransformation(), transform.GetProjectedTransformation(), sceneCamera.GetPosition(), material);
	/*// Go through each loaded mesh and out its contents
	for (int i = 0; i < objLoader.LoadedMeshes.size(); i++)
	{
		objLoader.LoadedMeshes[i].Draw();
	}*/

}

void Lina_Scene::CleanUp()
{

}
