FROM gcc:16
RUN apt modernize-sources && apt update && apt full-upgrade -y --no-install-recommends && apt autoremove
RUN apt install -y sudo cmake ninja-build gdb lldb clang-format llvm ccache
RUN mkdir -p -m 0700 ~/.ssh && ssh-keyscan github.com >> ~/.ssh/known_hosts
RUN adduser vscode
RUN passwd -d vscode
RUN usermod -G sudo vscode
USER vscode
RUN mkdir -p /home/vscode/.config/gdb/ && echo add-auto-load-safe-path /usr/local/lib64/libstdc++.so.6.0.35-gdb.py > /home/vscode/.config/gdb/gdbinit