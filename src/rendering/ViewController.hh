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
#ifndef VIEWCONTROLLER_HH
#define VIEWCONTROLLER_HH

namespace gazebo
{
  namespace common
  {
    class MouseEvent;
  }

	namespace rendering
  {
    class UserCamera;
  
    class ViewController
    {
      /// \brief Constructor
      public: ViewController(UserCamera *camera);
  
      /// \brief Destructor
      public: virtual ~ViewController();
  
      public: virtual void Update() = 0;
  
      /// \brief Handle a mouse event
      public: virtual void HandleMouseEvent(const common::MouseEvent &event)=0;
  
      protected: UserCamera *camera; 
    };
  }
}
#endif
