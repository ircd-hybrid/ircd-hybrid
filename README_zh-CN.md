# 任务目标

<!-- hy-mt2-i18n:start -->
[English](./README.md) | **中文** | [日本語](./README_ja.md) | [Español](./README_es.md)
<!-- hy-mt2-i18n:end -->

将下方 Markdown 格式数据翻译为中文。

# 严格约束
1. **只输出译文**。不要添加任何其他内容。
2. **结构锁定**：必须完全保持原有的 Markdown 数据结构、缩进、标题层级、表格、链接、URL、徽章、代码块和行内代码不变。
3. **选择性翻译**：仅翻译面向用户展示的可见自然语言内容（正文、标题、说明文字和表格文本）。
4. **禁止修改**：**严禁**翻译或更改代码标签、键名、变量占位符（如 {{var}}、${var}、%s、%d 等）、命令示例、文件路径、项目名、API 名、包名、模型名、标识符和代码符号；除非原文已经给出对应译名。

# 数据输入
源文件：README.md

Markdown 内容：
ircd-hybrid
&middot;
[![最新 Github 发布版本](https://img.shields.io/github/v/tag/ircd-hybrid/ircd-hybrid?color=425158&style=flat-square)](https://github.com/ircd-hybrid/ircd-hybrid/tags)
[![构建状态](https://img.shields.io/github/actions/workflow/status/ircd-hybrid/ircd-hybrid/ci.yml?branch=8.2.x&color=425158&style=flat-square)](https://github.com/ircd-hybrid/ircd-hybrid/actions/workflows/ci.yml)
[![Coverity 扫描结果](https://img.shields.io/coverity/scan/ircd-hybrid-ircd-hybrid?color=425158&style=flat-square)](https://scan.coverity.com/projects/ircd-hybrid-ircd-hybrid)
=====
一个轻量级且高性能的互联网中继聊天守护进程。其设计目标是实现快速响应与稳定运行。自1997年起便一直为各种 irc 网络提供支持。

## 要求条件
ircd-hybrid 需要运行在符合 POSIX 标准的操作系统上，例如 GNU/Linux、GNU/Hurd、*BSD 系列或 macOS。

## 安装指南
有关配置和编译 ircd-hybrid 的详细信息，请参阅 [INSTALL.md](INSTALL.md) 文档。

## 技术支持
如果您需要帮助或希望更深入地了解该软件，可以加入我们的 irc 社区——irc.ircd-hybrid.org 上的 #ircd-coders 频道。

## 许可协议
ircd-hybrid 遵循 **GNU 通用公共许可证 v2.0** 的许可条款。该许可证的完整版本可在本仓库中的 [COPYING.md](COPYING.md) 文件中找到。
