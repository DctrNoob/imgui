#ifndef IMGUI_FIXED_STRING_H
#define IMGUI_FIXED_STRING_H

#include "ab/util/fixedstring.hpp"
#include "imgui.h"

namespace ImGui {
template <size_t TCapacity>
IMGUI_API bool InputText(const char* label, ab::TFixedString<TCapacity>* str,
                         ImGuiInputTextFlags flags = 0,
                         ImGuiInputTextCallback callback = NULL,
                         void* user_data = NULL);

template <size_t TCapacity>
IMGUI_API bool InputTextMultiline(const char* label,
                                  ab::TFixedString<TCapacity>* str,
                                  const ImVec2& size = ImVec2(0, 0),
                                  ImGuiInputTextFlags flags = 0,
                                  ImGuiInputTextCallback callback = NULL,
                                  void* user_data = NULL);

template <size_t TCapacity>
IMGUI_API bool InputTextWithHint(const char* label, const char* hint,
                                 ab::TFixedString<TCapacity>* str,
                                 ImGuiInputTextFlags flags = 0,
                                 ImGuiInputTextCallback callback = NULL,
                                 void* user_data = NULL);
}  // namespace ImGui

#include "imgui_fixedstring.inl"

#endif
