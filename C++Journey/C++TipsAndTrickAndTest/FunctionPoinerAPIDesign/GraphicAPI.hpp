#ifndef _GRAPHIC_API_HPP
#define _GRAPHIC_API_HPP

#include <iostream>
#include <string>

#include "./Libraries/OpenGL/OpenGL.hpp"
#include "./Libraries/Vulkan/Vulkan.hpp"
#include "./Libraries/DirectX/DirectX.hpp"

class GraphicAPI {
	enum class BackendAPI {
		OpenGL = 0,
		Vulkan,
		DirectX
	};

public:
	
	GraphicAPI(): bAPI(BackendAPI::OpenGL){}
	
	~GraphicAPI(){
		//
	}


	void setBackendAPI(std::string backendAPIName ) {
		
		if(backendAPIName == "OpenGL") 
		{
			bAPI = BackendAPI::OpenGL;	
		} 
		else if(backendAPIName == "Vulkan") 
		{
			bAPI = BackendAPI::Vulkan;
		} 
		else if(backendAPIName == "DirectX")
		{
			bAPI = BackendAPI::DirectX;
		} 
		else 
		{
			bAPI = BackendAPI::OpenGL;
		}
		
	}
	
	BackendAPI getBackdAPI() {
		return BackendAPI::OpenGL;
	}

	void  drawCircle(void (**drawCircleF)() ) {
		 if(bAPI == BackendAPI::OpenGL) 
		 {
		 	*drawCircleF = &openGLDrawCircle;
		 } 
		 else if (bAPI == BackendAPI::Vulkan) 
		 {
		 	*drawCircleF = &vulkanDrawCircle;
		 } 
		 else if (bAPI == BackendAPI::DirectX) 
		 {
		 	*drawCircleF = &directXDrawCircle;
		 } 
	}

	void drawRectangle(void (**drawRectangleF)() ) {
		if(bAPI == BackendAPI::OpenGL) 
	 	{
		 	*drawRectangleF = openGLDrawRectangle;
		} 
		else if (bAPI == BackendAPI::Vulkan) 
		{
			*drawRectangleF = vulkanDrawRectangle;
		} 
		else if (bAPI == BackendAPI::DirectX) 
		{
			*drawRectangleF = directXDrawRectangle;
		} 
	}


	void* getDrawCircle() {
		 if(bAPI == BackendAPI::OpenGL) 
		 {
		 	drawCircleLF = (void*)openGLDrawCircle;
		 } 
		 else if (bAPI == BackendAPI::Vulkan) 
		 {
		 	drawCircleLF = (void*)vulkanDrawCircle;
		 } 
		 else if (bAPI == BackendAPI::DirectX) 
		 {
		 	drawCircleLF = (void*)directXDrawCircle;
		 } 

		return drawCircleLF;
	}
	
	void* getDrawRectangle() {
		
		if(bAPI == BackendAPI::OpenGL) 
	 	{
		 	drawRectangleLF = (void*)openGLDrawRectangle;
		} 
		else if (bAPI == BackendAPI::Vulkan) 
		{
			drawRectangleLF = (void*)vulkanDrawRectangle;
		} 
		else if (bAPI == BackendAPI::DirectX) 
		{
			drawRectangleLF = (void*)directXDrawRectangle;
		}

		return drawRectangleLF;
	}



private:
	void *drawCircleLF;
	void *drawRectangleLF;

	
private:
	BackendAPI bAPI;
};


#endif
