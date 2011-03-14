/*
 * Copyright 2011 Nate Koenig & Andrew Howard
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *
*/
#include "rendering/Camera.hh"
#include "EntityMaker.hh"

using namespace gazebo;

bool EntityMaker::snapToGrid = true;
double EntityMaker::snapDistance = 0.2;
double EntityMaker::snapGridSize = 1.0;

////////////////////////////////////////////////////////////////////////////////
/// Constructor
EntityMaker::EntityMaker()
{
}

////////////////////////////////////////////////////////////////////////////////
/// Destructor
EntityMaker::~EntityMaker()
{
}

////////////////////////////////////////////////////////////////////////////////
/// Set whether to snap to grid
void EntityMaker::SetSnapToGrid(bool snap)
{
  snapToGrid = snap;
}


////////////////////////////////////////////////////////////////////////////////
void EntityMaker::MousePushCB(const MouseEvent &event)
{
}

////////////////////////////////////////////////////////////////////////////////
void EntityMaker::MouseReleaseCB(const MouseEvent &event)
{
}

////////////////////////////////////////////////////////////////////////////////
void EntityMaker::MouseDragCB(const MouseEvent &event)
{
}

////////////////////////////////////////////////////////////////////////////////
// Get a point snapped to a grid
Vector3 EntityMaker::GetSnappedPoint(Vector3 p)
{
  Vector3 result = p;

  if (this->snapToGrid)
  {
    Vector3 rounded = (p / this->snapGridSize).GetRounded() * this->snapGridSize;
    if (p.Distance( rounded ) < this->snapDistance)
      result = rounded;
  }

  return result;
}
