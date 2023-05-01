#! /usr/bin/env bash
set -euo pipefail

echo "What kind of version bump? (major|minor|patch)"
read version_bump

echo "npm version $version_bump"
npm version $version_bump

echo "npm publish"
npm publish

echo "git push --follow-tags"
git push --follow-tags