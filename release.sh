#! /usr/bin/env bash

set -euo pipefail

npm version $1
git push --follow-tags
npm publish