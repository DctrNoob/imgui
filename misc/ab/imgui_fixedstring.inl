namespace ImGui {
namespace intern {
template <size_t TCapacity>
struct InputTextCallback_UserData {
  ab::TFixedString<TCapacity>* Str;
  ImGuiInputTextCallback ChainCallback;
  void* ChainCallbackUserData;
};

template <size_t TCapacity>
int InputTextCallback(ImGuiInputTextCallbackData* data) {
  InputTextCallback_UserData<TCapacity>* user_data =
      (InputTextCallback_UserData<TCapacity>*)data->UserData;
  if (data->EventFlag == ImGuiInputTextFlags_CallbackResize) {
    // Resize string callback
    // If for some reason we refuse the new length (BufTextLen) and/or capacity
    // (BufSize) we need to set them back to what we want.
    auto str = user_data->Str;
    IM_ASSERT(data->Buf == str->c_str());
    data->BufTextLen = static_cast<int>(str->resize(data->BufTextLen));
    data->BufDirty = true;
    data->Buf = (char*)str->c_str();
  } else if (user_data->ChainCallback) {
    // Forward to user callback, if any
    data->UserData = user_data->ChainCallbackUserData;
    return user_data->ChainCallback(data);
  }
  return 0;
}
}  // namespace intern

template <size_t TCapacity>
bool InputText(const char* label, ab::TFixedString<TCapacity>* str,
               ImGuiInputTextFlags flags, ImGuiInputTextCallback callback,
               void* user_data) {
  IM_ASSERT((flags & ImGuiInputTextFlags_CallbackResize) == 0);
  flags |= ImGuiInputTextFlags_CallbackResize;

  intern::InputTextCallback_UserData<TCapacity> cb_user_data;
  cb_user_data.Str = str;
  cb_user_data.ChainCallback = callback;
  cb_user_data.ChainCallbackUserData = user_data;
  return InputText(label, (char*)str->c_str(), str->capacity() + 1, flags,
                   intern::InputTextCallback<TCapacity>, &cb_user_data);
}

template <size_t TCapacity>
bool InputTextMultiline(const char* label, ab::TFixedString<TCapacity>* str,
                        const ImVec2& size, ImGuiInputTextFlags flags,
                        ImGuiInputTextCallback callback, void* user_data) {
  IM_ASSERT((flags & ImGuiInputTextFlags_CallbackResize) == 0);
  flags |= ImGuiInputTextFlags_CallbackResize;

  intern::InputTextCallback_UserData<TCapacity> cb_user_data;
  cb_user_data.Str = str;
  cb_user_data.ChainCallback = callback;
  cb_user_data.ChainCallbackUserData = user_data;
  return InputTextMultiline(label, (char*)str->c_str(), str->capacity() + 1,
                            size, flags, intern::InputTextCallback<TCapacity>,
                            &cb_user_data);
}

template <size_t TCapacity>
bool InputTextWithHint(const char* label, const char* hint,
                       ab::TFixedString<TCapacity>* str,
                       ImGuiInputTextFlags flags,
                       ImGuiInputTextCallback callback, void* user_data) {
  IM_ASSERT((flags & ImGuiInputTextFlags_CallbackResize) == 0);
  flags |= ImGuiInputTextFlags_CallbackResize;

  intern::InputTextCallback_UserData<TCapacity> cb_user_data;
  cb_user_data.Str = str;
  cb_user_data.ChainCallback = callback;
  cb_user_data.ChainCallbackUserData = user_data;
  return InputTextWithHint(label, hint, (char*)str->c_str(),
                           str->capacity() + 1, flags,
                           intern::InputTextCallback<TCapacity>, &cb_user_data);
}
}  // namespace ImGui
