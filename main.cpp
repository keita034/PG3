#include <stdio.h>
#include <stdlib.h>
#include<memory>
#include<vector>
#include"IShape.h"
#include"Rectangle.h"
#include"Circle.h"


int main()
{

	std::vector<std::unique_ptr<IShape>>shapes;

	shapes.push_back(std::move(std::make_unique<Circle>(5.0f)));

	shapes.push_back(std::move(std::make_unique<Rectangle>(10.f, 20.f)));

	for (std::unique_ptr<IShape>&shape : shapes)
	{
		printf("}Œ`‚Ì–ÊÏ%f\n", shape->GetSize());
	}
	printf("\n");

	for (std::unique_ptr<IShape>& shape : shapes)
	{
		shape->Draw();
	}

	system("pause");

	return 0;
}