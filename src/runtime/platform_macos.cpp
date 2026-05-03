#include "support.hpp"
#include <dispatch/dispatch.h>
#import <Foundation/Foundation.h>

namespace dino::runtime {
    void dispatch_on_ui_thread(std::function<void()> func) {
        if ([NSThread isMainThread]) {
            func();
        } else {
            dispatch_sync(dispatch_get_main_queue(), ^{
                func();
            });
        }
    }

    std::filesystem::path get_bundle_resource_directory() {
        return std::filesystem::current_path();
    }
}
