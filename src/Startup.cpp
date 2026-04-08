#include <Geode/Geode.hpp>
#include <Geode/binding/PlatformToolbox.hpp>
#include "platform/Platform.hpp"

using namespace geode::prelude;

class PlatformScheduler : public CCObject {
public:
    void update(float dt) {
        PlatformManager::get()->update();
    }
};


$execute {
    auto platform = PlatformManager::get();
    
    Loader::get()->queueInMainThread([]{
        CCScheduler::get()->scheduleUpdateForTarget(new PlatformScheduler{}, 2000, false);
    });
}