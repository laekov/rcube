var vueFiles = ['bower_components/vue/dist/vue.min.js'];
var threejsFiles = ['bower_components/three.js/build/three.min.js'];
var jqueryFiles = ['bower_components/jquery/dist/jquery.min.js'];

module.exports = function(grunt) {
	grunt.initConfig({
		pkg: grunt.file.readJSON('package.json'),
		uglify: {
			vue: {
				files: {
					'dists/vue.js': vueFiles,
					'dists/threejs.js': threejsFiles,
					'dists/jquery.js': jqueryFiles,
				}
			}
		}
    });
    grunt.loadNpmTasks('grunt-contrib-uglify');
    grunt.registerTask('default', [ 'uglify' ]);
};
