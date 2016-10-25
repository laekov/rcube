vueFiles = ['bower_components/vue/dist/vue.min.js'];

module.exports = function(grunt) {
	grunt.initConfig({
		pkg: grunt.file.readJSON('package.json'),
		uglify: {
			vue: {
				files: {
					'dists/vue.js': vueFiles
				}
			}
		}
    });
    grunt.loadNpmTasks('grunt-contrib-uglify');
    grunt.registerTask('default', [ 'uglify' ]);
};
