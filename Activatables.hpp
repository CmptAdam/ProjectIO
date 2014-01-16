/*
 * Copyright 2013 Cepheid
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
*/
#ifndef ActivatablesHPP
#define ActivatablesHPP

#include "Graphics.hpp"
#include "Common.hpp"
#include "Entity.hpp"

namespace io {
  class Activatable {
  public:
    Activatable() {
    }

    virtual ~Activatable() { }

    virtual void activate(Entity* activator) = 0;

    virtual void draw(Graphics* g) { }

    virtual bool isSolid() const {
      return true;
    }
  private:
  };

  enum class Orientation : int8_t {
    HORIZONTAL,
    VERTICAL
  };

  class Door : public Activatable {
  public:
    Door() {
      orientation = Orientation::HORIZONTAL;
    }

    virtual ~Door() {

    }

    virtual void activate(Entity* activator) {
      if (getOrientation() == Orientation::VERTICAL) {
        switch(activator->getFacing()) {
        case Facing::NORTH:
          activator->setY(activator->getY() - 2);
          break;
        case Facing::SOUTH:
          activator->setY(activator->getY() + 2);
          break;
        default:
          break;
        }
      }
      else {
        switch(activator->getFacing()) {
        case Facing::EAST:
          activator->setX(activator->getX() + 2);
          break;
        case Facing::WEST:
          activator->setX(activator->getX() - 2);
          break;
        default:
          break;
        }
      }
    }

    Orientation getOrientation() const {
      return orientation;
    }

    void setOrientation(const Orientation orientation) {
      this->orientation = orientation;
    }
  private:
    Orientation orientation;
  };

  enum class SecretDoorDirection : int8_t {
    NORTH,
    EAST,
    SOUTH,
    WEST,
    NORTH_SOUTH,
    EAST_WEST
  };

  class SecretDoor : public Activatable {
  public:
    SecretDoor() {
      setDirection(SecretDoorDirection::NORTH);
    }

    virtual ~SecretDoor() {

    }

    virtual void activate(Entity* activator) {
      switch(getDirection()) {
      case SecretDoorDirection::NORTH:
        if (activator->getFacing() == Facing::NORTH) {
          activator->setY(activator->getY() - 2);
        }
        break;
      case SecretDoorDirection::EAST:
        if (activator->getFacing() == Facing::EAST) {
          activator->setX(activator->getX() + 2);
        }
        break;
      case SecretDoorDirection::SOUTH:
        if (activator->getFacing() == Facing::SOUTH) {
          activator->setY(activator->getY() + 2);
        }
        break;
      case SecretDoorDirection::WEST:
        if (activator->getFacing() == Facing::WEST) {
          activator->setX(activator->getX() - 2);
        }
        break;
      case SecretDoorDirection::NORTH_SOUTH:
        switch (activator->getFacing()) {
        case Facing::NORTH:
          activator->setY(activator->getY() - 2);
          break;
        case Facing::SOUTH:
          activator->setY(activator->getY() + 2);
          break;
        default:
          break;
        }
        break;
      case SecretDoorDirection::EAST_WEST:
        switch(activator->getFacing()) {
        case Facing::EAST:
          activator->setX(activator->getX() + 2);
          break;
        case Facing::WEST:
          activator->setX(activator->getX() - 2);
          break;
        default:
          break;
        }
        break;
      }
    }

    SecretDoorDirection getDirection() const {
      return direction;
    }

    void setDirection(const SecretDoorDirection direction) {
      this->direction = direction;
    }
  private:
    SecretDoorDirection direction;
  };

  enum class StairDirection {
    UP,
    DOWN
  };

  class Stairs : public Activatable {
  public:
    Stairs() {
      setDirection(StairDirection::UP);
    }

    virtual ~Stairs() {

    }

    virtual void activate(Entity* activator) {

    }

    StairDirection getDirection() const {
      return direction;
    }

    void setDirection(const StairDirection direction) {
      this->direction = direction;
    }
  private:
    StairDirection direction;
  };
}

#endif
