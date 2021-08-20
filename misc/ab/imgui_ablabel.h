#ifndef IMGUI_ABLABEL_H
#define IMGUI_ABLABEL_H

#include "ab/util/fixedstring.hpp"
#include "imgui.h"

namespace ImGui {
IMGUI_API bool InputText(const char* label, ab::label_t* str,
                         ImGuiInputTextFlags flags = 0,
                         ImGuiInputTextCallback callback = NULL,
                         void* user_data = NULL);

IMGUI_API bool InputTextMultiline(const char* label, ab::label_t* str,
                                  const ImVec2& size = ImVec2(0, 0),
                                  ImGuiInputTextFlags flags = 0,
                                  ImGuiInputTextCallback callback = NULL,
                                  void* user_data = NULL);

IMGUI_API bool InputTextWithHint(const char* label, const char* hint,
                                 ab::label_t* str,
                                 ImGuiInputTextFlags flags = 0,
                                 ImGuiInputTextCallback callback = NULL,
                                 void* user_data = NULL);
}  // namespace ImGui

#endif
